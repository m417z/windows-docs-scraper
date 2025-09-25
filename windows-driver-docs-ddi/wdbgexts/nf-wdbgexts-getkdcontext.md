# GetKdContext macro

## Description

The **GetKdContext** function returns the total number of processors and the number of the current processor in the structure *ppi* points to.

## Parameters

### `ppi`

Points to the following structure:

```cpp
typedef struct _PROCESSORINFO {
  USHORT  Processor;           // current processor
  USHORT  NumberProcessors;    // total number of processors
} PROCESSORINFO, *PPROCESSORINFO;
```

## Remarks

### Returns

The total number of processors in the structure.