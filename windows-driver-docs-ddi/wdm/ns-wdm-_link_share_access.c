typedef struct _LINK_SHARE_ACCESS {
  ULONG OpenCount;
  ULONG Deleters;
  ULONG SharedDelete;
} LINK_SHARE_ACCESS, *PLINK_SHARE_ACCESS;