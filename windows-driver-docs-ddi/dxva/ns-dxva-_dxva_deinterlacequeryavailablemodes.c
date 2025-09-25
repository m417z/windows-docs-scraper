typedef struct _DXVA_DeinterlaceQueryAvailableModes {
  DWORD Size;
  DWORD NumGuids;
  GUID  Guids[MAX_DEINTERLACE_DEVICE_GUIDS];
} DXVA_DeinterlaceQueryAvailableModes;