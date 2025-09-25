# DIFFOBJECTATTRIBUTES structure

## Description

The DIFFOBJECTATTRIBUTES structure describes the information contained in the "FFAttributes" value of the registry key for each "object" on a force-feedback device. If the "FFAttributes" value is absent, then the object is assumed not to support force feedback.

## Members

### `dwFFMaxForce`

Specifies the magnitude of the maximum force that can be created by the actuator associated with this object. Force is expressed in Newtons and measured in relation to where the hand would be during **Normal** operation of the device. If this member is zero, the object is assumed not to support force feedback.

### `dwFFForceResolution`

Specifies the force resolution of the actuator associated with this object. The returned value represents the number of gradations, or subdivisions, of the maximum force that can be expressed by the force feedback system from 0 (no force) to maximum force.