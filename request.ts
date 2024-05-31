// 封装 axios
import axios from "axios";
import { useRouter } from "vue-router";
const router = useRouter();

const http = axios.create({
  baseURL: "http://localhost:8080",
  timeout: 1000,
});

http.interceptors.request.use(
  (config) => {
    const url = config.url || ""; // Default to empty string if undefined
    const noAuthRequired = ["/login", "/register"];

    if (!noAuthRequired.includes(url)) {
      // const token = localStorage.getItem('token');
      // if (token) {
      // 后端 jwt 来不及调试了。设置了 fakenToken
      config.headers[
        "Authorization"
      ] = `Bearer eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJzdWIiOiJhZG1pbiJ9.OHoCtIeYlrtmmCi_9_uGLG6qmPUVB69EZk2-4Q6cjgs`;
      // }
    }

    return config;
  },
  (error) => {
    // Do something with request error
    return Promise.reject(error);
  }
);

// http.interceptors.response.use(
//   function (response) {
//     // 在这里可以访问到响应头
//     const token = response.headers["authorization"];
//     console.log(token);
//     localStorage.setItem("token", token); // 使用lo
//     // 确保你仍然返回响应以便后续的代码可以继续处理
//     return response;
//   },
//   function (error) {
//     // 对响应错误做点什么
//     return Promise.reject(error);
//   }
// );

export default http;
