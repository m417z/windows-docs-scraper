# PFND3DKMT_BUDGETCHANGENOTIFICATIONCALLBACK callback function

## Description

The **PFND3DKMT_BUDGETCHANGENOTIFICATIONCALLBACK** callback function notifies of a budget change.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_BUDGETCHANGENOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_budgetchangenotification) structure.

## Prototype

```cpp
//Declaration

PFND3DKMT_BUDGETCHANGENOTIFICATIONCALLBACK Pfnd3dkmtBudgetchangenotificationcallback;

// Definition

VOID Pfnd3dkmtBudgetchangenotificationcallback
(
  D3DKMT_BUDGETCHANGENOTIFICATION *
)
{...}

```