# _DXVA_COPPSetSignalingCmdData structure

## Description

The DXVA_COPPSetSignalingCmdData structure describes how to protect the signal that goes through the physical connector associated with the DirectX VA COPP device.

## Members

### `ActiveTVProtectionStandard`

Specifies a valid ORed combination of the following values from the **COPP_TVProtectionStandard** enumeration type that indicates the type of television signals on which to set protection:

* COPP_ProtectionStandard_Unknown (0x80000000)
* COPP_ProtectionStandard_None (0x00000000)
* COPP_ProtectionStandard_IEC61880_525i (0x00000001)
* COPP_ProtectionStandard_IEC61880_2_525i (0x00000002)
* COPP_ProtectionStandard_IEC62375_625p (0x00000004)
* COPP_ProtectionStandard_EIA608B_525 (0x00000008)
* COPP_ProtectionStandard_EN300294_625i (0x00000010)
* COPP_ProtectionStandard_CEA805A_TypeA_525p (0x00000020)
* COPP_ProtectionStandard_CEA805A_TypeA_750p (0x00000040)
* COPP_ProtectionStandard_CEA805A_TypeA_1125i (0x00000080)
* COPP_ProtectionStandard_CEA805A_TypeB_525p (0x00000100)
* COPP_ProtectionStandard_CEA805A_TypeB_750p (0x00000200)
* COPP_ProtectionStandard_CEA805A_TypeB_1125i (0x00000400)
* COPP_ProtectionStandard_ARIBTRB15_525i (0x00000800)
* COPP_ProtectionStandard_ARIBTRB15_525p (0x00001000)
* COPP_ProtectionStandard_ARIBTRB15_750p (0x00002000)
* COPP_ProtectionStandard_ARIBTRB15_1125i (0x00004000)

### `AspectRatioChangeMask1`

Specifies the COPP_ImageAspectRatio_EN300294_Mask (0x00000007) constant that indicates that only the first 3 bits in the following **AspectRatioData1** member are valid.

### `AspectRatioData1`

Specifies one of the following values from the **COPP_ImageAspectRatio_EN300294** enumeration type to indicate an ETSI EN 300 294 value.

* COPP_AspectRatio_EN300294_FullFormat4by3 (0)
* COPP_AspectRatio_EN300294_Box14by9Center (1)
* COPP_AspectRatio_EN300294_Box14by9Top (2)
* COPP_AspectRatio_EN300294_Box16by9Center (3)
* COPP_AspectRatio_EN300294_Box16by9Top (4)
* COPP_AspectRatio_EN300294_BoxGT16by9Center (5)
* COPP_AspectRatio_EN300294_FullFormat4by3ProtectedCenter (6)
* COPP_AspectRatio_EN300294_FullFormat16by9Anamorphic (7)

### `AspectRatioChangeMask2`

Specifies a value that indicates the valid bitfields in the following **AspectRatioData2** member.

### `AspectRatioData2`

Specifies 32-bit data for additional aspect ratio-related data to be set for specific protection standards. This data can be used to express End and Q0 values for EIA-608-B, or active format description for CEA-805-A Type B packets.

### `AspectRatioChangeMask3`

Specifies a value that indicates the valid bitfields in the following **AspectRatioData3** member.

### `AspectRatioData3`

Specifies 32-bit data for additional aspect ratio-related data to be set for specific protection standards. This data can be used to express End and Q0 values for EIA-608-B, or active format description for CEA-805-A Type B packets.

### `ExtendedInfoChangeMask`

Specifies an array of values that indicate the valid bitfields in the respective elements of the following **ExtendedInfoData** array member.

### `ExtendedInfoData`

Specifies an array of additional 32-bit data values to be set. Not currently used.

### `Reserved`

Reserved. Should be set to zero.

## See also

[COPPCommand](https://learn.microsoft.com/windows-hardware/drivers/display/coppcommand)

[DXVA_COPPCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_coppcommand)