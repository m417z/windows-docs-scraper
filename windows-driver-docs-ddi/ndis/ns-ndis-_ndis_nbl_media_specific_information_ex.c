typedef struct _NDIS_NBL_MEDIA_SPECIFIC_INFORMATION_EX {
  NDIS_OBJECT_HEADER                             Header;
  struct _NDIS_NBL_MEDIA_SPECIFIC_INFORMATION_EX *NextEntry;
  ULONG                                          Tag;
  PVOID                                          Data;
} NDIS_NBL_MEDIA_SPECIFIC_INFORMATION_EX, *PNDIS_NBL_MEDIA_SPECIFIC_INFORMATION_EX;