// stores/authStore.js
import { defineStore } from 'pinia';

export const useAuthStore = defineStore('auth', {
  state: () => ({
    token: null
  }),
  actions: {
    setToken(newToken: any) {
      this.token = newToken;
    },
    clearToken() {
      this.token = null;
    }
  },
  persist: true,
  getters: {
    isLoggedIn: (state) => !!state.token
  }
});
