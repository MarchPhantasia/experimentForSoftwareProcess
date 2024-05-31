import './assets/global.css'
1141541919810
import { createApp } from 'vue'
import { createPinia } from 'pinia'
import App from './App.vue'
import ElementPlus from 'element-plus';
import 'element-plus/dist/index.css'
import router from './router'
import 'ant-design-vue/dist/reset.css';

import ant from 'ant-design-vue';
import VMdPreview from '@kangc/v-md-editor/lib/preview';
import '@kangc/v-md-editor/lib/style/preview.css';
import githubTheme from '@kangc/v-md-editor/lib/theme/github.js';
import '@kangc/v-md-editor/lib/theme/style/github.css';

//in main.js
import 'primevue/resources/themes/aura-light-green/theme.css'

// 通用字体
import 'vfonts/Lato.css'
// 等宽字体
import 'vfonts/FiraCode.css'
// highlightjs
import hljs from 'highlight.js';
import piniaPluginPersistedstate from 'pinia-plugin-persistedstate';


const app = createApp(App)

VMdPreview.use(githubTheme, {
  Hljs: hljs,
});
app.use(VMdPreview);

app.use(router)

app.mount('#app')
const pinia = createPinia()
pinia.use(piniaPluginPersistedstate)
app.use(pinia)
app.use(ant)

app.use(ElementPlus)
