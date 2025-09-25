# PROBLEM_TYPE enumeration

## Description

The **PROBLEM_TYPE** enumeration describes the type of problem a helper class indicates is present.

## Constants

### `PT_INVALID:0`

### `PT_LOW_HEALTH:1`

A low-health problem exists within the component itself. No problems were found within local components on which this component depends.

### `PT_LOWER_HEALTH:2`

A low-health problem exists within local components on which this component depends.

### `PT_DOWN_STREAM_HEALTH:4`

The low-health problem is in the out-of-box components this component depends on.

### `PT_HIGH_UTILIZATION:8`

The component's resource is being highly utilized. No high utilization was found within local components on which this component depends.

### `PT_HIGHER_UTILIZATION:16`

 The causes of the component's high-utilization problem are from local components that depend on it.

### `PT_UP_STREAM_UTILIZATION:32`

The causes of the component's high-utilization problem are from upstream network components that depend on it.