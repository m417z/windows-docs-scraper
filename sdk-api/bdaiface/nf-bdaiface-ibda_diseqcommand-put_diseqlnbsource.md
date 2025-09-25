# IBDA_DiseqCommand::put_DiseqLNBSource

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Sets the low-noise block (LNB) converter source.

## Parameters

### `ulLNBSource` [in]

The LNB converter source to use.

| Value | Meaning |
| --- | --- |
| **0** | Source position A. |
| **1** | Source position B. |
| **2** | Source position C. |
| **3** | Source position D. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_DiseqCommand](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_diseqcommand)