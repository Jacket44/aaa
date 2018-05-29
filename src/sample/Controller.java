package sample;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;
import java.util.ResourceBundle;

public class Controller implements Initializable {
    @FXML
    private TextField textField;
    @FXML
    private TextArea textArea;

    @FXML
    private void inputAction() {
        try {
            String[] command = {"a.out", textField.getText()};
            Process process = new ProcessBuilder(command).start();
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(process.getInputStream()));

            String result;

            while ((result = bufferedReader.readLine()) != null) {
                textArea.appendText(textField.getText() + " := " + result + "\n");
                textField.clear();
            }

        } catch (IOException ex) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("ERROR");
            alert.setHeaderText("Error");
            alert.setContentText("IOException!");
            alert.showAndWait();
        }
    }

    @Override
    public void initialize(URL url, ResourceBundle rb) {
    }
}
