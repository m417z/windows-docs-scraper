LSTATUS SHRegEnumUSKeyA(
  [in]      HUSKEY          hUSKey,
  [in]      DWORD           dwIndex,
  [out]     LPSTR           pszName,
  [in, out] LPDWORD         pcchName,
  [in]      SHREGENUM_FLAGS enumRegFlags
);