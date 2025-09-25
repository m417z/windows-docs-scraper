# NdisGetCurrentProcessorCounts function

## Description

The
**NdisGetCurrentProcessorCounts** function returns counts for the current processor that a driver can use
to determine CPU usage for a particular time interval.

## Parameters

### `pIdleCount` [out]

A pointer to a caller-supplied variable in which this function returns the cumulative idle time
for the processor since the system was booted.

### `pKernelAndUser` [out]

A pointer to a caller-supplied variable in which this function returns the cumulative processing
time (kernel-mode time plus user-mode time) for the processor since the system was booted.

### `pIndex` [out]

A pointer to a caller-supplied variable in which this function returns a zero-based index that
identifies the processor within the computer.

## Remarks

**NdisGetCurrentProcessorCounts** returns idle and CPU-usage counts that the caller can use to
determine CPU usage for the current processor. The CPU utilization value indicates how loaded the CPU was
since the immediately preceding call to this function. If the CPU was heavily loaded, such a driver can
change how it handles certain operations to improve driver performance.

**Note** Estimating processor usage is difficult, and drivers generally don't do it. Note that, even if you have an accurate estimate of processor usage, there are other factors that you need to take into account, such as what is causing the load on the CPU – and how important that particular load might be.

A driver might call
**NdisGetCurrentProcessorCounts** periodically within a timer function. The driver can use the
following calculation to determine the CPU usage for a multiple of the timer interval:

```
CpuUsage = 100-100*(Idle - Idle[n])/(KernelAndUser - KernelAndUser[n]);
```

where:

* CpuUsage is CPU usage as a percentage of the total interval time
* Idle is the
  *IdleCount* value returned by the most recent call to
  **NdisGetCurrentProcessorCounts**
* Idle[n] is an
  *IdleCount* value returned by a previous call, stored as the nth element in an array
* KernelandUser is the
  *KernelAndUser* value returned by the most recent call to
  **NdisGetCurrentProcessorCounts**
* KernelandUser[n] is the KernelandUser value returned by a previous call, stored as the nth element
  in an array