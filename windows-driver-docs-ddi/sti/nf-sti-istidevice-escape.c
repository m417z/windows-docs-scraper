HRESULT Escape(
  [in]      STI_RAW_CONTROL_CODE EscapeFunction,
  [in]      LPVOID               lpInData,
            DWORD                cbInDataSize,
  [in, out] LPVOID               pOutData,
            DWORD                dwOutDataSize,
  [out]     LPDWORD              pdwActualData
);