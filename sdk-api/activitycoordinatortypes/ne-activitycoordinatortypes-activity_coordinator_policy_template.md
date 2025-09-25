## Description

An enumeration of the set of supported template policies. These templates cover the needs of most activities, but developers should customize their policies where needed to ensure that all resources are configured appropriately for their activity.

## Constants

### `ACTIVITY_COORDINATOR_POLICY_TEMPLATE_GOOD`

Activities that run using this policy as configured are highly unlikely to interfere with most user experiences and system performance as long as unconfigured resources are not consumed.

### `ACTIVITY_COORDINATOR_POLICY_TEMPLATE_MEDIUM`

Activities that run using this policy as configured may interfere with user experiences and system performance, but will not critically degrade them as long as unconfigured resources are not consumed.

The resource conditions for this template configuration are more likely to be satisfied than the GOOD template, but the potential to impact user-experiences and system performance is also greater.

### `ACTIVITY_COORDINATOR_POLICY_TEMPLATE_BASE`

This template represents the minimum recommended resource conditions. This helps ensure that, at a minimum, activities do not critically degrade most user experiences and system performance for the most common resources needed by all activities.

### `ACTIVITY_COORDINATOR_POLICY_TEMPLATE_EMPTY`

This template represents an empty policy. It's used as the basis for a completely custom policy implementation.

## Remarks

[!IMPORTANT]
Template configurations are provided below for reference only. *Configurations may be updated in the future to meet user needs as common workflows and system configurations evolve.* However, such updates will not break the reasonable expectations these policies provide. Updates will primarily be limited to new conditions for previously unconfigured resources, particularly when adding new resource types. Updates will not remove configurations for already configured resources in a template.

### Available conditions for resources

#### ACTIVITY_COORDINATOR_POLICY_TEMPLATE_GOOD

| Resource | Available value |
|-----|-----|
| User-Idle | ACTIVITY_COORDINATOR_CONDITION_GOOD |
| Power | ACTIVITY_COORDINATOR_CONDITION_GOOD |
| Network | ACTIVITY_COORDINATOR_CONDITION_NOT_SET |
| CPU | ACTIVITY_COORDINATOR_CONDITION_GOOD |
| Memory | ACTIVITY_COORDINATOR_CONDITION_GOOD |
| System-Disk | ACTIVITY_COORDINATOR_CONDITION_GOOD |
| GPU | ACTIVITY_COORDINATOR_CONDITION_NOT_SET |

#### ACTIVITY_COORDINATOR_POLICY_TEMPLATE_MEDIUM

| Resource | Available value |
|-----|-----|
| User-Idle | ACTIVITY_COORDINATOR_CONDITION_MEDIUM |
| Power | ACTIVITY_COORDINATOR_CONDITION_MEDIUM |
| Network | ACTIVITY_COORDINATOR_CONDITION_NOT_SET |
| CPU | ACTIVITY_COORDINATOR_CONDITION_MEDIUM |
| Memory | ACTIVITY_COORDINATOR_CONDITION_MEDIUM |
| System-Disk | ACTIVITY_COORDINATOR_CONDITION_MEDIUM |
| GPU | ACTIVITY_COORDINATOR_CONDITION_NOT_SET |

#### ACTIVITY_COORDINATOR_POLICY_TEMPLATE_BASE

| Resource | Available value |
|-----|-----|
| User-Idle | ACTIVITY_COORDINATOR_CONDITION_GOOD |
| Power | ACTIVITY_COORDINATOR_CONDITION_GOOD |
| Network | ACTIVITY_COORDINATOR_CONDITION_NOT_SET |
| CPU | ACTIVITY_COORDINATOR_CONDITION_MEDIUM |
| Memory | ACTIVITY_COORDINATOR_CONDITION_MEDIUM |
| System-Disk | ACTIVITY_COORDINATOR_CONDITION_MEDIUM |
| GPU | ACTIVITY_COORDINATOR_CONDITION_NOT_SET |

#### ACTIVITY_COORDINATOR_POLICY_TEMPLATE_EMPTY

| Resource | Available value |
|-----|-----|
| User-Idle | ACTIVITY_COORDINATOR_CONDITION_NOT_SET |
| Power | ACTIVITY_COORDINATOR_CONDITION_NOT_SET |
| Network | ACTIVITY_COORDINATOR_CONDITION_NOT_SET |
| CPU | ACTIVITY_COORDINATOR_CONDITION_NOT_SET |
| Memory | ACTIVITY_COORDINATOR_CONDITION_NOT_SET |
| System-Disk | ACTIVITY_COORDINATOR_CONDITION_NOT_SET |
| GPU | ACTIVITY_COORDINATOR_CONDITION_NOT_SET |

## See also

[CreateActivityCoordinatorPolicy](https://learn.microsoft.com/windows/win32/api/activitycoordinator/nf-activitycoordinator-createactivitycoordinatorpolicy)

[ACTIVITY_COORDINATOR_CONDITION](https://learn.microsoft.com/windows/win32/api/activitycoordinatortypes/ne-activitycoordinatortypes-activity_coordinator_condition)

[ACTIVITY_COORDINATOR_RESOURCE](https://learn.microsoft.com/windows/win32/api/activitycoordinatortypes/ne-activitycoordinatortypes-activity_coordinator_resource)