# Programming in C: Assignment

Four C / Arduino programs covering sensor processing, control flow, functions and recursion, and an Arduino smart parking system. The full write-ups and screenshots are in the PDF report.

**Report (PDF):** https://docs.google.com/document/d/1N6wdo0H_UESV09mzfjW_V4O0t2vSMGCqEuxbOy-WEIs/edit?usp=sharing

## Files

| Question | File | Description |
|---|---|---|
| Q1 | `q1_water_quality.c` | Calculates a water-quality index from temperature and turbidity and classifies the water |
| Q2 | `q2_mobile_money.c` | Menu-driven mobile-money system (deposit, withdraw, balance, summary) |
| Q3 | `q3_delivery_distance.c` | Delivery route analysis using functions and a recursive sum |
| Q4 | `q4_smart_parking/q4_smart_parking.ino` | Arduino parking-space monitor (ultrasonic sensor, LEDs, buzzer) |

Q4 screenshots (circuit, block diagram, test cases) are in `q4_smart_parking/screenshots/`.

## How to compile and run (Q1 to Q3)

```
gcc -Wall q1_water_quality.c -o water_quality
./q1_water_quality
```

```
gcc -Wall q2_mobile_money.c -o mobile_money
./mobile_money
```

```
gcc -Wall q3_delivery_distance.c -o delivery_distance
./delivery_distance
```

## Q4: Tinkercad simulation

Tinkercad project: https://www.tinkercad.com/things/4HvVXWR5zWN/editel?sharecode=RYFO3aAzh5eZZVCYVPfPeXBaHUfu9sWaQSuZP_Sb3bA

Wiring: TRIG to pin 9, ECHO to pin 10, green LED to pin 4, red LED to pin 5, buzzer to pin 6. A vehicle within 50 cm turns on the red LED and buzzer, otherwise the green LED is on.

## Author

Manuelle Aseye Ackun, African Leadership University