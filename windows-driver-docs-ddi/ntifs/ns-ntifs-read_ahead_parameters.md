## Description

The **READ_AHEAD_PARAMETERS** structure contains read-ahead parameters.

## Members

### `NodeByteSize`

Size of the node, in bytes.

### `Granularity`

Granularity of read-aheads. This value must be an even power of 2 and greater than, or equal to PAGE_SIZE.

### `PipelinedRequestSize`

The request size to be used when performing pipelined read-aheads, in bytes. Each read-ahead request that is pipelined is broken into smaller **PipelinedRequestSize**-sized requests. This is typically used to increase the throughput by parallelizing multiple requests instead of one single big one.

For backward compatibility, the Cache Manager will break every read-ahead request into two if this value is zero.

### `ReadAheadGrowthPercentage`

The growth of read ahead as a percentage of the data that has already been ready by the application so far.

## See also

[**CcReadAhead**](https://learn.microsoft.com/previous-versions/ff539191(v=vs.85))

[**CcScheduleReadAhead**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccschedulereadahead)