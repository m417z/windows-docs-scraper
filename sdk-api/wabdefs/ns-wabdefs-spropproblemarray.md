# SPropProblemArray structure

## Description

Do not use. Contains an array of one or more [SPropProblem](https://learn.microsoft.com/windows/desktop/api/wabdefs/ns-wabdefs-spropproblem) structures.

## Members

### `cProblem`

Type: **ULONG**

Variable of type **ULONG** that specifies the count of [SPropProblem](https://learn.microsoft.com/windows/desktop/api/wabdefs/ns-wabdefs-spropproblem) structures in the array indicated by the **aProblem** member.

### `aProblem`

Type: **[SPropProblem](https://learn.microsoft.com/windows/desktop/api/wabdefs/ns-wabdefs-spropproblem)[MAPI_DIM]**

Array of variables of type [SPropProblem](https://learn.microsoft.com/windows/desktop/api/wabdefs/ns-wabdefs-spropproblem) that specify information about a property error.