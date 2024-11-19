# Enygma machne

- Key is pressed -- letter X is entered
- Rotor 3 "advances"
- 3 rotors. each performs a substitution:
  - Rot3(X) ==> X'
  - Rot2(X') ==> X''
  - Rot1(X'') ==> Y
- One reflector, also performing a substitution
  - Refl(Y) ==> Y'
- Finally, the result of reflector goes back through the inverse of the rotors, in reverse order
  - Inv(Rot1(Y')) ==> Z
  - Inv(Rot2(Z)) ==> Z'
  - Inv(Rot3(Z')) ==> Z''

- At a certain ponit, rotor 3 "catches" rotor two and causes it to rotate by one
- Similarly, there is a "catch" on rotor two, which moves rotor 1

Reference: TT
