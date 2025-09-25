typedef struct _LINKED_DEVICE {
  ULONG   ChainUid;
  ULONG   NumberOfLinksInChain;
  BOOLEAN LeadLink;
} LINKED_DEVICE, *PLINKED_DEVICE;