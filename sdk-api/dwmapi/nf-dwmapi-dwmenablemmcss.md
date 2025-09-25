# DwmEnableMMCSS function

## Description

Notifies the Desktop Window Manager (DWM) to opt in to or out of Multimedia Class Schedule Service (MMCSS) scheduling while the calling process is alive.

## Parameters

### `fEnableMMCSS` [in]

**TRUE** to instruct DWM to participate in MMCSS scheduling; **FALSE** to opt out or end participation in MMCSS scheduling.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

DWM will be scheduled by the MMCSS as long as any process that called **DwmEnableMMCSS** to enable MMCSS is active and has not previously called **DwmEnableMMCSS** to disable MMCSS.