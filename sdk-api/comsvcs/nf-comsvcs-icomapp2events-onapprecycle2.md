# IComApp2Events::OnAppRecycle2

## Description

Generated when the server application process is marked for recycling termination.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidApp` [in]

The application ID.

### `guidProcess` [in]

The process ID.

### `lReason` [in]

The reason code that explains why a process was recycled. The following codes are defined.

| Value | Meaning |
| --- | --- |
| **CRR_NO_REASON_SUPPLIED**<br><br>0x00000000 | The reason is not specified. |
| **CRR_LIFETIME_LIMIT**<br><br>xFFFFFFFF | The specified number of minutes that an application runs before recycling was reached. |
| **CRR_ACTIVATION_LIMIT**<br><br>0xFFFFFFFE | The specified number of activations was reached. |
| **CRR_CALL_LIMIT**<br><br>0xFFFFFFFD | The specified number of calls to configured objects in the application was reached. |
| **CRR_MEMORY_LIMIT**<br><br>0xFFFFFFFC | The specified memory usage that a process cannot exceed was reached. |
| **CRR_RECYCLED_FROM_UI**<br><br>xFFFFFFFB | An administrator decided to recycle the process through the Component Services administration tool. |

## Return value

The user verifies the return values from this method.

## See also

[IComApp2Events](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomapp2events)