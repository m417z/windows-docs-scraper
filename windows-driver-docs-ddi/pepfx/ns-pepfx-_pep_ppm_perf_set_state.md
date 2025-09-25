# _PEP_PPM_PERF_SET_STATE structure (pepfx.h)

## Description

Used in the **PEP_NOTIFY_PPM_PERF_SET** notification at runtime to set the current operating performance of the processor.

## Members

### `MinimumPerformanceState`

On input, the new requested minimum performance state. This state is defined as the absolute minimum instantaneous performance level at which the processor may run. The operating system may set this value to any performance value in the range [Lowest Performance, Guaranteed Performance], inclusive. Minimum performance must never be set to a value higher than maximum performance.

### `MaximumPerformanceState`

On input, the new requested maximum performance state. This state is defined as the absolute maximum instantaneous performance level at which the processor may run. The OS may set Maximum performance to any performance value in the range [Lowest Performance, Highest Performance], inclusive.

### `DesiredPerformanceState`

On input, the new requested desired performance state. This state is defined as the performance level power manager is requesting from the processor. Desired performance may be set to any performance value in the range [Minimum Performance, Maximum Performance], inclusive. Desired performance may take one of two meanings, depending on whether the desired performance is above or below the guaranteed performance level.

- Below the guaranteed performance level, desired performance expresses the average performance level the platform must provide.
- Above the guaranteed performance level, the platform must provide the guaranteed performance level. The platform should attempt to provide up to the desired performance level, if current operating conditions allow for it, but it is not required to do so.

### `EnergyPerformancePreference`

On input, the new requested energy performance preference for the processor.

## See also

- [Processor power management (PPM) notifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/)