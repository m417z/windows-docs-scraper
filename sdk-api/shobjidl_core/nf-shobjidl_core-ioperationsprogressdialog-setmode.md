# IOperationsProgressDialog::SetMode

## Description

Sets progress dialog operations mode.

## Parameters

### `mode` [in]

Type: **PDMODE**

Specifies the operation mode. The following are valid values.

#### PDM_DEFAULT

0x00000000. Use the default progress dialog operations mode.

#### PDM_RUN

0x00000001. The operation is running.

#### PDM_PREFLIGHT

0x00000002. The operation is gathering data before it begins, such as calculating the predicted operation time.

#### PDM_UNDOING

0x00000004. The operation is rolling back due to an Undo command from the user.

#### PDM_ERRORSBLOCKING

0x00000008. Error dialogs are blocking progress from continuing.

#### PDM_INDETERMINATE

0x00000010. The length of the operation is indeterminate. Do not show a timer and display the progress bar in marquee mode.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.