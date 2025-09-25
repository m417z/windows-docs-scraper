typedef struct FWPM_VSWITCH_EVENT0_ {
  FWPM_VSWITCH_EVENT_TYPE eventType;
  wchar_t                 *vSwitchId;
  union {
    struct {
      ULONG  numvSwitchFilterExtensions;
      LPWSTR *vSwitchFilterExtensions;
    } positionInfo;
    struct {
      BOOL   inRequiredPosition;
      ULONG  numvSwitchFilterExtensions;
      LPWSTR *vSwitchFilterExtensions;
    } reorderInfo;
  };
} FWPM_VSWITCH_EVENT0;