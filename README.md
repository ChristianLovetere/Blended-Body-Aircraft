# Blended Body Aircraft
 A blended body aircraft that serves as the proof of concept for special landing gear that can rotate and elevate independently.

<p align="center">
  <img src="Photos/PlaneFront.jpg" alt="Image 1" width="45%">
  <img src="Photos/PlaneProfile.jpg" alt="Image 2" width="45%">
</p>

We use the NX6 Controller to control the drone. This controller is made for use with hobby drones, and the corresponding receiver is attached to the plane. The receiver natively controls the aileron servos, and the servos and actuators for the landing gear are controlled via Arduino. The receiver values on the channels that correspond to arduino-controlled components are sent to the arduino itself to do some simple processing.

<p align="center">
  <img src="Photos/NX6.jpg" alt="Controller Image" width="50%">
</p>

Schematic available ![here](PlaneWiringSchematic.pdf).

