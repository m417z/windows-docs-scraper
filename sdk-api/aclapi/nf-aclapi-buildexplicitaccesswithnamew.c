VOID BuildExplicitAccessWithNameW(
  [in, out]      PEXPLICIT_ACCESS_W pExplicitAccess,
  [in, optional] LPWSTR             pTrusteeName,
  [in]           DWORD              AccessPermissions,
  [in]           ACCESS_MODE        AccessMode,
  [in]           DWORD              Inheritance
);