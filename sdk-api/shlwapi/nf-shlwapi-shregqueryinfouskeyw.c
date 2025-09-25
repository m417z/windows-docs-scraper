LSTATUS SHRegQueryInfoUSKeyW(
  [in]            HUSKEY          hUSKey,
  [out, optional] LPDWORD         pcSubKeys,
  [out, optional] LPDWORD         pcchMaxSubKeyLen,
  [out, optional] LPDWORD         pcValues,
  [out, optional] LPDWORD         pcchMaxValueNameLen,
  [in]            SHREGENUM_FLAGS enumRegFlags
);