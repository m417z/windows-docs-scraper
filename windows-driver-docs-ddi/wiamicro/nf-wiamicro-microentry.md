# MicroEntry function

## Description

The **MicroEntry** function responds to commands sent by the WIA Flatbed driver.

## Parameters

### `lCommand`

Specifies a command issued to the microdriver by the WIA Flatbed driver.

### `pValue` [in, out]

Points to a [VAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamicro/ns-wiamicro-val) structure that is used to pass information between the WIA Flatbed driver and the microdriver.

## Return value

If the function succeeds, it returns S_OK. If a passed command is not supported, the function returns E_NOTIMPL. For any error, error information must be put in the **lVal** member of the VAL structure pointed to by *pValue*.

## Remarks

This function performs many different tasks, depending on the command passed in the *lCommand* parameter. See the [WIA Microdriver Commands](https://learn.microsoft.com/windows-hardware/drivers/image/wia-microdriver-commands) reference section for a list of these commands.

Two structures are passed to the function. A [VAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamicro/ns-wiamicro-val) structure is passed in the *pValue* pointer, and the **pScanInfo** member of the VAL structure points to a [SCANINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamicro/ns-wiamicro-_scaninfo) structure. The VAL structure is used to pass information between the WIA Flatbed Driver and the microdriver. The SCANINFO structure is used to store and communicate parameters of a scan data acquisition. Many of the commands passed to this function set values in the SCANINFO structure.

## See also

[SCANINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamicro/ns-wiamicro-_scaninfo)

[VAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamicro/ns-wiamicro-val)

[WIA Microdriver Commands](https://learn.microsoft.com/windows-hardware/drivers/image/wia-microdriver-commands)

[WIA Microdriver Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)