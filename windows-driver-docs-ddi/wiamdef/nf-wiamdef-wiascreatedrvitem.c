HRESULT wiasCreateDrvItem(
            LONG        lObjectFlags,
            BSTR        bstrItemName,
            BSTR        bstrFullItemName,
  [in, out] IWiaMiniDrv *pIMiniDrv,
            LONG        cbDevSpecContext,
  [out]     BYTE        **ppDevSpecContext,
  [out]     IWiaDrvItem **ppIWiaDrvItem
);