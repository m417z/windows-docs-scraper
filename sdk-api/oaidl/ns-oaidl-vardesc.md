# VARDESC structure

## Description

Describes a variable, constant, or data member.

## Members

### `memid`

The member ID.

### `lpstrSchema`

Reserved.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.oInst`

With VAR_PERINSTANCE, the offset of this variable within the instance.

### `DUMMYUNIONNAME.lpvarValue`

With VAR_CONST, the value of the constant.

### `elemdescVar`

The variable type.

### `wVarFlags`

The variable flags. See [VARFLAGS](https://learn.microsoft.com/windows/desktop/api/oaidl/ne-oaidl-varflags).

### `varkind`

The variable type.