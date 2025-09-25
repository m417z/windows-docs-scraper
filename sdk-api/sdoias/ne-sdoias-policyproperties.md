# POLICYPROPERTIES enumeration

## Description

The values of the **POLICYPROPERTIES** enumeration type enumerate properties of a
Network Access Policy (NAP).

## Constants

### `PROPERTY_POLICY_CONSTRAINT`

String that contains all the text of the conditions.

Do not use this property to access the Conditions; use the
**PROPERTY_POLICY_CONDITIONS_COLLECTION** instead.

### `PROPERTY_POLICY_MERIT`

Specifies the relative position of this policy with respect to other policies.

In the UI, the upper-most policy in the UI has a merit value of 1, the next one down has a merit value of 2,
and so on.

You cannot set the merit value of a policy when you first create the object. A new policy object is always
applied in the same merit location. To order your policies, create the policy object and set its values. Apply
all the changes to the object, and then set the appropriate merit value and apply the changes.

### `PROPERTY_POLICY_UNUSED0`

This property is reserved.

### `PROPERTY_POLICY_UNUSED1`

This property is reserved.

### `PROPERTY_POLICY_PROFILE_NAME`

Specifies the profile name. This property is used by the system to associate the policy with the
profile.

### `PROPERTY_POLICY_ACTION`

Specifies the name of the profile associated with the policy. This property is not currently used. Use
**PROPERTY_POLICY_PROFILE_NAME** instead.

### `PROPERTY_POLICY_CONDITIONS_COLLECTION`

Specifies the conditions for this network access policy.

### `PROPERTY_POLICY_ENABLED`

Used by NPS user interface in policy evaluation. If the policy is not enabled, its configuration is present
but it is not applied.

### `PROPERTY_POLICY_SOURCETAG`

Used by NPS user interface to tag a set of policies to be applicable only for a specified kind of RADIUS
client (or source). For example, a policy tagged by "DHCP Server."

## Remarks

To create a new policy, you must specify a unique name for the policy, a profile to associate with the policy,
and a collection of conditions for the policy. The name of the policy and the name of the profile should be
identical.

## See also

[CONDITIONPROPERTIES](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-conditionproperties)