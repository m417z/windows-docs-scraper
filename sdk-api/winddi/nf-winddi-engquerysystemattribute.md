# EngQuerySystemAttribute function

## Description

The **EngQuerySystemAttribute** function queries processor-specific or system-specific capabilities.

## Parameters

### `CapNum` [in]

Specifies the capability being queried. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| **EngNumberOfProcessors** | GDI returns the number of active processors in the system. |
| **EngOptimumAvailableSystemMemory** | Not available for use. |
| **EngOptimumAvailableUserMemory** | Not available for use. |
| **EngProcessorFeature** | GDI returns a bitmask of flags that describe the features of the processor. Currently, GDI sets the QSA_MMX flag when an *x86* processor has MMX support. QSA_MMX is relevant only on the *x86* platform. |

### `pCapability` [out]

Pointer to the location that receives the result of the query. The value that GDI places in this parameter depends on the enumerated value specified by *CapNum*.

## Return value

**EngQuerySystemAttribute** returns **TRUE** upon success. Otherwise, it returns **FALSE**.