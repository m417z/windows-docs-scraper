# LUID structure

## Description

A LUID (locally unique identifier) is a 64-bit value guaranteed to be unique only on the system on which it was generated. The uniqueness of a LUID is guaranteed only until the system is restarted.

A LUID is not for direct manipulation. Drivers must use support routines and structures to manipulate LUID values.

## Members

### `LowPart`

Low order bits.

### `HighPart`

High order bits.

## Syntax

```cpp
typedef struct _LUID {
  DWORD LowPart;
  LONG  HighPart;
} LUID, *PLUID;
```