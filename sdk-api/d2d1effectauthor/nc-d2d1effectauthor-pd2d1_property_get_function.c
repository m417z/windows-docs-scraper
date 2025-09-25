PD2D1_PROPERTY_GET_FUNCTION Pd2d1PropertyGetFunction;

HRESULT Pd2d1PropertyGetFunction(
  [in]            const IUnknown *effect,
  [out]           BYTE *data,
                  UINT32 dataSize,
  [out, optional] UINT32 *actualSize
)
{...}