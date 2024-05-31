import { createRouter, createWebHistory } from 'vue-router'
import { useAuthStore } from '@/stores/authStore';

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
      path: '/',
      name: 'home',
      component: () => import('@/views/BlogPage.vue')
    },
    {
      path: '/blogs',
      name: 'blogs',
      component: () => import('@/views/BlogPage.vue')
    },
    {
      path: '/blog/:id',
      name: 'blog',
      component: () => import('@/views/BlogDetail.vue')
    },
    {
      path: '/tags',
      name: 'tags',
      component: () => import('@/views/TagsPage.vue')
    },
    {
      path: '/changepage',
      name: 'changeepage',
      component: () => import('@/views/ChangePage.vue')
    },
        {
      path: '/publish',
      name: 'publish',
      component: () => import('@/views/Publish.vue')
    },
    {
      path: '/login',
      name: 'Login',
      component: () => import('@/views/Login.vue'),
      meta: {
        hideHeader: true,
        hideLayout: true
      }
    },

    // {
    //   path: '/about',
    //   name: 'about',
    //   // route level code-splitting
    //   // this generates a separate chunk (About.[hash].js) for this route
    //   // which is lazy-loaded when the route is visited.
    //   component: () => import('../views/AboutView.vue')
    // }
  ]
})



router.beforeEach((to, from, next) => {
  const authStore = useAuthStore();
  const requiresAuth = to.matched.some(record => record.meta.requiresAuth);
  const sessionStart = localStorage.getItem('session_start');
  const currentTime = new Date().getTime();
  const sessionDuration = 20 * 60 * 1000; // 20分钟
  if (to.name !== 'Login' && (!sessionStart || (currentTime - parseInt(sessionStart) > sessionDuration))){
    // 如果需要认证且用户未登录，重定向到登录页面
    next({ path: '/login' });
  } else {
    // 否则继续
    next();
  }
});



export default router
