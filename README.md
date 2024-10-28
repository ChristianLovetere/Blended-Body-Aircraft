# Blended Body Aircraft
 A blended body aircraft that serves as the proof of concept for special landing gear that can rotate and elevate independently of one another. Rotation allows the plane to be parked in a hangar horizontally, which is more convenient than taking a multiple point turn to park.

<p align="center">
  <img src="Photos/PlaneFront.jpg" alt="Image 1" width="45%">
  <img src="Photos/PlaneProfile.jpg" alt="Image 2" width="45%">
</p>

We use the NX6 Controller to control the drone. This controller is made for use with hobby drones, and the corresponding receiver is attached to the plane. The receiver natively controls the aileron servos, and the servos and actuators for the landing gear are controlled via Arduino. For Arduino-managed components, the receiver values are sent to the Arduino, and we use those values to decide which mode to engage. For example, the frequency for the 'up' position of a double throw switch on the controller will extend the landing gear fully. The 'down' position on this switch will retract them fully.

<p align="center">
  <img src="Photos/bba_down.jpg" alt="Image 1" width="30%">
  <img src="Photos/bba_tilt.jpg" alt="Image 2" width="30%">
  <img src="Photos/bba_up.jpg" alt="Image 2" width="30%">
</p>

<p align="center">
  <img src="Photos/NX6.jpg" alt="Controller Image" width="50%">
</p>

Schematic available ![here](PlaneWiringSchematic.pdf).

