HRESULT ColorimetricToDeviceColorsWithBlack(
  [in]  UINT                   cColors,
  [in]  UINT                   cChannels,
  [out] const XYZColorF        *pXYZColors,
  [in]  const BlackInformation *pBlackInformation,
  [in]  FLOAT                  *pDeviceValues
);