typedef struct _VIDEOMEMORY {
  DWORD   dwFlags;
  FLATPTR fpStart;
  union {
    FLATPTR fpEnd;
    DWORD   dwWidth;
  };
  DDSCAPS ddsCaps;
  DDSCAPS ddsCapsAlt;
  union {
#if ...
    _VMEMHEAP        *lpHeap;
#else
    struct _VMEMHEAP *lpHeap;
#endif
    DWORD            dwHeight;
  };
} VIDEOMEMORY;