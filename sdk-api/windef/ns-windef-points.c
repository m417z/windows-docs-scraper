typedef struct tagPOINTS {
#if ...
  SHORT x;
#if ...
  SHORT y;
#else
  SHORT y;
#endif
#else
  SHORT x;
#endif
} POINTS, *PPOINTS, *LPPOINTS;