## Description

The **LPEVALCOMCALLBACK** specification defines a callback function prototype. The [IValidate::SetStatus](https://learn.microsoft.com/windows/desktop/api/evalcom2/nf-evalcom2-ivalidate-setstatus) method enables an authoring tool to receive information about the progress of validation through the registered callback function.

## Parameters

### `iStatus` [in]

Specifies the status message sent by evalcom2.

| Value | Meaning |
| --- | --- |
| **NULL** | The value of this param |
| **ieStatusICECount**<br><br>1 | Number of ICEs that are being run. |
| **ieStatusMerge**<br><br>2 | Merging the package or merge module with the .cub file. |
| **ieStatusSummaryInfo**<br><br>3 | Merging summary information streams. |
| **ieStatusCreateEngine**<br><br>4 | Preparing to run the ICEs. |
| **ieStatusRunICE**<br><br>5 | Running an individual ICE. |
| **ieStatusStarting**<br><br>6 | Starting validation. |
| **ieStatusShutdown**<br><br>7 | Finish running the ICEs. |
| **ieStatusSuccess**<br><br>8 | Validation completed successfully. |
| **ieStatusFail**<br><br>9 | Validation failed. |
| **ieStatusCancel**<br><br>10 | Validation was canceled. |

### `szData`

A string value containing information appropriate to the status. The value of *szwData* should be the number of ICEs that are being run if *iStatus* is **ieStatusICECount**. The value of *szwData* should be the name of the ICE being run if *iStatus* is **ieStatusRunICE**. Otherwise, the value of *szwData* should be **NULL**. The callback function should accept **NULL** as a possible value for this parameter.

### `pContext`

Pointer to an application context passed to the [SetStatus](https://learn.microsoft.com/windows/desktop/api/evalcom2/nf-evalcom2-ivalidate-setstatus) method. This parameter can be used for error checking.

## Return value

| Return code/value | Description |
| --- | --- |
| ****TRUE****<br><br>1 | Validation procedure should continue. |
| ****FALSE****<br><br>0 | Validation was canceled. The callback function return **FALSE** to stop validation. |

## Remarks

The [SetStatus](https://learn.microsoft.com/windows/desktop/api/evalcom2/nf-evalcom2-ivalidate-setstatus) method and **LPEVALCOMCALLBACK** can be used to provide progress information. For example, the **ieStatusICECount** message can provide the overall tick count for a progress bar. For each **ieStatusRunICE** message received, the caller can increment the progress bar one tick.

## See also

[IValidate](https://learn.microsoft.com/windows/desktop/api/evalcom2/nn-evalcom2-ivalidate)

[Using Evalcom2](https://learn.microsoft.com/windows/desktop/Msi/using-evalcom2)

[Validation Callback Functions](https://learn.microsoft.com/windows/desktop/Msi/validation-callback-functions)