typedef struct _ACX_KEYWORDSPOTTER_CONFIG {
  ULONG                         Size;
  ULONG                         Id;
  const GUID                    *Name;
  ULONG                         Flags;
  const GUID                    *Pattern;
  PACX_KEYWORDSPOTTER_CALLBACKS Callbacks;
} ACX_KEYWORDSPOTTER_CONFIG, *PACX_KEYWORDSPOTTER_CONFIG;