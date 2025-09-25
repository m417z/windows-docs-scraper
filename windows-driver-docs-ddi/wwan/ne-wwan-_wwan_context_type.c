typedef enum _WWAN_CONTEXT_TYPE {
  WwanContextTypeNone,
  WwanContextTypeInternet,
  WwanContextTypeVpn,
  WwanContextTypeVoice,
  WwanContextTypeVideoShare,
  WwanContextTypeCustom,
  WwanContextTypePurchase,
  WwanContextTypeMms,
  WwanContextTypeIms,
  WwanContextTypeAdmin,
  WwanContextTypeApp,
  WwanContextTypeXcap,
  WwanContextTypeTethering,
  WwanContextTypeEmergencyCall,
  WwanContextTypeLteAttach,
  WwanContextTypeSupl,
  WwanContextTypeMax
} WWAN_CONTEXT_TYPE, *PWWAN_CONTEXT_TYPE;