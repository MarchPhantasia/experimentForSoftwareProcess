import { defineStore } from 'pinia'

export const useSearchKeywordStore = defineStore('searchKeyword', {
  state: () => ({
    searchKeyword: '',
  }),
  actions: {
    setSearchKeyword(keyword: string) {
      this.searchKeyword = keyword
    },
  },
})