# _DXVA_COPPSetProtectionLevelCmdData structure

## Description

The DXVA_COPPSetProtectionLevelCmdData structure describes the protection types and levels to set on the physical connector associated with a COPP DirectX VA device.

## Members

### `ProtType`

Specifies one of the following protection types to set on the physical connector associated with a COPP device:

* COPP_ProtectionType_None (0x00)
* COPP_ProtectionType_HDCP (0x01)
* COPP_ProtectionType_ACP (0x02)
* COPP_ProtectionType_CGMSA (0x04)

### `ProtLevel`

Specifies the protection level to set for the protection type in **ProtType** or COPP_NoProtectionLevelAvailable (-1) if no protection level is available.

* For COPP_ProtectionType_ACP, specifies one of the following values from the **COPP_ACP_Protection_Level** enumerated type:
  + COPP_ACP_Level0 or COPP_ACP_LevelMin (0)
  + COPP_ACP_Level1 (1)
  + COPP_ACP_Level2 (2)
  + COPP_ACP_Level3 or COPP_ACP_LevelMax (3)
* For COPP_ProtectionType_CGMSA, specifies one of the following values from the **COPP_CGMSA_Protection_Level** enumerated type:
  + COPP_CGMSA_Disabled or COPP_CGMSA_LevelMin (0)
  + COPP_CGMSA_CopyFreely (1)
  + COPP_CGMSA_CopyNoMore (2)
  + COPP_CGMSA_CopyOneGeneration (3)
  + COPP_CGMSA_CopyNever (4)
  + COPP_CGMSA_RedistributionControlRequired (0x08)
  + (COPP_CGMSA_RedistributionControlRequired + COPP_CGMSA_CopyNever) or COPP_CGMSA_LevelMax
* For COPP_ProtectionType_HDCP, specifies one of the following values from the **COPP_HDCP_Protection_Level** enumerated type:
  + COPP_HDCP_Level0 or COPP_HDCP_LevelMin (0)
  + COPP_HDCP_Level1 or COPP_HDCP_LevelMax (1)

### `ExtendedInfoChangeMask`

Specifies a value that indicates the valid bitfields in the following **ExtendedInfoData** member.

### `ExtendedInfoData`

Specifies additional 32-bit data for the protection type in **ProtType**. Not currently used.

## See also

[COPPCommand](https://learn.microsoft.com/windows-hardware/drivers/display/coppcommand)

[DXVA_COPPCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_coppcommand)