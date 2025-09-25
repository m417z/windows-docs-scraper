# IContinueCallback::FContinuePrinting

## Description

Indicates whether a lengthy printing operation should continue.

## Parameters

### `nCntPrinted` [in]

The total number of pages that have been printed at the time the object receives a call to **FContinuePrinting**.

### `nCurPage` [in]

The page number of the page being printed at the time the object receives a call to **FContinuePrinting**.

### `pwszPrintStatus` [in]

A pointer to the message about the current status of the print job. The object being printed may or may not display this message to the user. This parameter can be **NULL**.

## Return value

This method can return the standard return value E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Continue the printing operation. |
| **S_FALSE** | Cancel the printing operation as soon as possible. |

## Remarks

Implementations of [IPrint::Print](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iprint-print) call this method at periodic intervals during the printing process. The [IPrint](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-iprint) implementation should call back at least after printing each page, so that its client can, if necessary, display useful visual feedback to the user. **IPrint::Print** can call back multiple times with the same *nCntPrinted* and *nCurPage* values, which is sometimes useful when a page being printed is complex and it is appropriate to give a user an opportunity to cancel in mid-page.

## See also

[IContinueCallback](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-icontinuecallback)

[IPrint](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-iprint)