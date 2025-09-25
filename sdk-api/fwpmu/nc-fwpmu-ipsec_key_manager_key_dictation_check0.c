IPSEC_KEY_MANAGER_KEY_DICTATION_CHECK0 IpsecKeyManagerKeyDictationCheck0;

void IpsecKeyManagerKeyDictationCheck0(
  [in]  const IKEEXT_TRAFFIC0 *ikeTraffic,
  [out] BOOL *willDictateKey,
  [out] UINT32 *weight
)
{...}