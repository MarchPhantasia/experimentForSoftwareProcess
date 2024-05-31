import { getUserInfo } from "@/api/userAPI";
import { id } from "element-plus/es/locales.mjs";
import { defineStore } from "pinia";

export const useUserInfoStore = defineStore({
  id: "userInfo",
  state: () => ({
    id: "",
    username: "",
    email: "",
    phone: "",
    address: "",
    birthday: "",
    avatar: "",
  }),
  persist: {
    beforeRestore: (ctx) => {
      console.log(`即将恢复 '${ctx.store.$id}'`)
    },
    afterRestore: (ctx) => {
      console.log(`刚刚恢复完 '${ctx.store.$id}'`)
    },
  },
  actions: {
    setUserInfo(userInfo: any) {
      this.id = userInfo.id;
      this.username = userInfo.username;
      this.email = userInfo.email;
      this.phone = userInfo.phone;
      this.address = userInfo.address;
      this.birthday = userInfo.birthday;
      this.avatar = userInfo.avatar;
    },
  },
});
