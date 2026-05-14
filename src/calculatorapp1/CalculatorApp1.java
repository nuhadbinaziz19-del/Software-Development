/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/javafx/FXMain.java to edit this template
 */
package calculatorapp1;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

/**
 *
 * @author Nuhad
 */
public class CalculatorApp1 extends Application {
    
    double num1;
    String sign = ""; 

    @Override 
    public void start(Stage stage) {
        TextField screen = new TextField();
        screen.setEditable(false);
        screen.setPrefHeight(50);
        screen.setAlignment(Pos.CENTER_RIGHT); 
        Button one = new Button("1");
        Button two = new Button("2");
        Button three = new Button("3");
        Button four = new Button("4");
        Button five = new Button("5");
        Button six = new Button("6");
        Button seven = new Button("7");
        Button eight = new Button("8");
        Button nine = new Button("9");
        Button zero = new Button("0");
        Button plus = new Button("+");
        Button minus = new Button("-");
        Button multiply = new Button("*");
        Button divide = new Button("/");
        Button equal = new Button("=");
        Button clear = new Button("Clear");
        Button[] allButtons = {
                one, two, three, four, five,
                six, seven, eight, nine, zero,
                plus, minus, multiply, divide,
                equal, clear
        };
        for (Button b : allButtons) {
            b.setPrefSize(70, 50);
        }
        GridPane box = new GridPane();
        box.setHgap(5);
        box.setVgap(5);
        box.setAlignment(Pos.CENTER);
        box.add(one, 0, 0);
        box.add(two, 1, 0);
        box.add(three, 2, 0);
        box.add(four, 0, 1);
        box.add(five, 1, 1);
        box.add(six, 2, 1);
        box.add(seven, 0, 2);
        box.add(eight, 1, 2);
        box.add(nine, 2, 2);
        box.add(zero, 1, 3);
        box.add(plus, 3, 0);
        box.add(minus, 3, 1);
        box.add(multiply, 3, 2);
        box.add(divide, 3, 3);
        box.add(equal, 2, 3);
        box.add(clear, 0, 3);
        one.setOnAction(e -> screen.appendText("1"));
        two.setOnAction(e -> screen.appendText("2"));
        three.setOnAction(e -> screen.appendText("3"));
        four.setOnAction(e -> screen.appendText("4"));
        five.setOnAction(e -> screen.appendText("5"));
        six.setOnAction(e -> screen.appendText("6"));
        seven.setOnAction(e -> screen.appendText("7"));
        eight.setOnAction(e -> screen.appendText("8"));
        nine.setOnAction(e -> screen.appendText("9"));
        zero.setOnAction(e -> screen.appendText("0"));
        plus.setOnAction(e -> {
            if(!screen.getText().isEmpty()){
                num1 = Double.parseDouble(screen.getText());
                sign = "+";
                screen.clear();
            }
        }
        );
        minus.setOnAction(e -> {
            if(!screen.getText().isEmpty()){
                num1 = Double.parseDouble(screen.getText());
                sign = "-";
                screen.clear();
            }
        }
        );
        multiply.setOnAction(e -> {
            if(!screen.getText().isEmpty()){
                num1 = Double.parseDouble(screen.getText());
                sign = "*";
                screen.clear();
            }
        }
        );
        divide.setOnAction(e -> {
            if(!screen.getText().isEmpty()){
                num1 = Double.parseDouble(screen.getText());
                sign = "/";
                screen.clear();
            }
        }
        );
        equal.setOnAction((var e) -> {
            if(screen.getText().isEmpty() || sign.isEmpty()) return; 
            double num2 = Double.parseDouble(screen.getText());
            double answer = 0;
            switch (sign) {
                case "+" -> answer = num1 + num2;
                case "-" -> answer = num1 - num2;
                case "*" -> answer = num1 * num2;
                case "/" -> {
                    if (num2 == 0) {
                        screen.setText("Error");
                        return;
                    }   
                    answer = num1 / num2;
                }
            }
            screen.setText(String.valueOf(answer));
            sign = ""; 
        });
        clear.setOnAction(e -> {
            screen.clear();
            num1 = 0;
            sign = "";
        });
        BorderPane root = new BorderPane();
        root.setTop(screen);
        root.setCenter(box);
        Scene scene = new Scene(root, 350, 320);
        stage.setTitle("Calculator");
        stage.setScene(scene);
        stage.show();
    }
    public static void main(String[] args) {
        Application.launch(args);
    } 
    
}
