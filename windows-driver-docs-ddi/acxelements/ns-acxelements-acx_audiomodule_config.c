typedef struct _ACX_AUDIOMODULE_CONFIG {
  ULONG                      Size;
  ULONG                      Id;
  const GUID                 *Name;
  ULONG                      Flags;
  ACX_AUDIOMODULE_DESCRIPTOR Descriptor;
  PACX_AUDIOMODULE_CALLBACKS Callbacks;
} ACX_AUDIOMODULE_CONFIG, *PACX_AUDIOMODULE_CONFIG;