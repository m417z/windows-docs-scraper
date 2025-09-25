int getsourcefilter(
  [in]      SOCKET              Socket,
  [in]      ULONG               Interface,
  [in]      const SOCKADDR      *Group,
  [in]      int                 GroupLength,
  [out]     MULTICAST_MODE_TYPE *FilterMode,
  [in, out] ULONG               *SourceCount,
  [out]     SOCKADDR_STORAGE    *SourceList
);