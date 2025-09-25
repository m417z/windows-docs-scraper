# WppRecorderLogSetIdentifier macro

## Description

The [WppRecorderLogSetIdentifier](https://learn.microsoft.com/windows-hardware/drivers/ddi/wpprecorder/nf-wpprecorder-wpprecorderlogsetidentifier) method sets a string identifier for the recorder log.

## Parameters

### `RecorderLog` [in]

A recorder log handle returned in a previous call to [**WppRecorderLogCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wpprecorder/nf-wpprecorder-wpprecorderlogcreate).

### `LogIdentifier` [in]

A string identifier to set.

## Remarks

Do not call [WppRecorderLogSetIdentifier](https://learn.microsoft.com/windows-hardware/drivers/ddi/wpprecorder/nf-wpprecorder-wpprecorderlogsetidentifier) on the default log handle returned by [WppRecorderLogGetDefault](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/dn895240(v=vs.85)).