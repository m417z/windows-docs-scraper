typedef struct _WWAN_LADN {
  WCHAR         AccessString[WWAN_ACCESSSTRING_LEN];
  WWAN_TAI_LIST TaiList;
} WWAN_LADN, *PWWAN_LADN;