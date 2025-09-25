LSTATUS SHRegEnumUSKeyW(
  [in]      HUSKEY          hUSKey,
  [in]      DWORD           dwIndex,
            LPWSTR          pwzName,
  [in, out] LPDWORD         pcchName,
  [in]      SHREGENUM_FLAGS enumRegFlags
);