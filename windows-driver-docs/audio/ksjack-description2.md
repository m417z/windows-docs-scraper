# KSJACK\_DESCRIPTION2 structure

The `KSJACK_DESCRIPTION2` structure specifies the capabilities and the current state of a jack that supports jack presence detection.

## Members

**DeviceStateInfo**
Specifies the lower 16 bits of the DWORD parameter. This parameter indicates whether the jack is currently active, streaming, idle, or hardware not ready.

**JackCapabilities**
Specifies the lower 16 bits of the DWORD parameter. This parameter is a flag and it indicates the capabilities of the jack. This flag can be set to one of the values in the following table.

|  |  |
| --- | --- |
| **Flag** | **Meaning** |
| JACKDESC2_PRESENCE_DETECT_CAPABILITY (0x00000001) | Jack supports jack presence detection. |
| JACKDESC2_DYNAMIC_FORMAT_CHANGE_CAPABILITY (0x00000002) | Jack supports dynamic format change. |

For more information about dynamic format change, see [Dynamic Format Change](https://learn.microsoft.com/windows-hardware/drivers/audio/dynamic-format-change).

## Remarks

If an audio device lacks jack presence detection, the **IsConnected** member of the [**KSJACK\_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/audio/ksjack-description) structure must always be set to **TRUE**. To remove the ambiguity that results from this dual meaning of the **TRUE** value for **IsConnected**, a client application can call [IKsJackDescription2::GetJackDescription2](https://learn.microsoft.com/windows/win32/api/devicetopology/nf-devicetopology-iksjackdescription2-getjackdescription2) to read the **JackCapabilities** flag of the `KSJACK_DESCRIPTION2` structure. If this flag has the JACKDESC2\_PRESENCE\_DETECT\_CAPABILITY bit set, it indicates that the endpoint does in fact support jack presence detection. In that case, the return value of the **IsConnected** member can be interpreted to accurately reflect the insertion status of the jack.

## Requirements

|  |  |
| --- | --- |
| Version | Available in Windows 7 and later Windows operating systems. |
| Header | Ksmedia.h (include Ksmedia.h) |

## See also

[**KSJACK\_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/audio/ksjack-description)

[IKsJackDescription2::GetJackDescription2](https://learn.microsoft.com/windows/win32/api/devicetopology/nf-devicetopology-iksjackdescription2-getjackdescription2)

