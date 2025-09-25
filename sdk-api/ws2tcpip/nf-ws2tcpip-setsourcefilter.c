int setsourcefilter(
  [in] SOCKET                 Socket,
  [in] ULONG                  Interface,
  [in] const SOCKADDR         *Group,
  [in] int                    GroupLength,
  [in] MULTICAST_MODE_TYPE    FilterMode,
  [in] ULONG                  SourceCount,
  [in] const SOCKADDR_STORAGE *SourceList
);