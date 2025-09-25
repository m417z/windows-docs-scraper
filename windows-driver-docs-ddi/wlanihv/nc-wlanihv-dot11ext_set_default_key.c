DOT11EXT_SET_DEFAULT_KEY Dot11extSetDefaultKey;

DWORD Dot11extSetDefaultKey(
  [in, optional] HANDLE hDot11SvcHandle,
  [in]           PDOT11_CIPHER_DEFAULT_KEY_VALUE pKey,
  [in]           DOT11_DIRECTION dot11Direction
)
{...}