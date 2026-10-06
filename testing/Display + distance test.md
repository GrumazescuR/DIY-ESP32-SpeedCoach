# GPS Distance Test

## Aim

Test whether the L76K GPS can be used to measure distance travelled and see how stable the measurement is when stationary.

## Initial stationary test

The first version calculated distance between each new GPS position.

While the prototype was sitting still, the displayed distance slowly increased to around 17 m. This showed that small changes in the GPS position were being counted as movement.

A 3 m threshold was added so movements smaller than 3 m would be ignored.

After this change, the distance stayed at 0 m for around a minute while stationary.

## First walking test

When tested outside, the distance stayed at 0 m even while walking.

The problem was that the stored GPS position was being updated after every reading. This meant several small movements could never build up enough to pass the 3 m threshold.

The code was changed so the stored position only updates after movement greater than 3 m has been accepted.

## Second walking test

A short walk of roughly 5 m was then measured at around 7-10 m.

This showed that actual movement was now being detected. However, after returning inside and leaving the prototype stationary for around a minute, the distance continued to increase.

## Result

The basic distance calculation is working, but GPS drift can still be mistaken for movement.

The next step is to improve the movement detection, likely by using GPS speed alongside the position data.
