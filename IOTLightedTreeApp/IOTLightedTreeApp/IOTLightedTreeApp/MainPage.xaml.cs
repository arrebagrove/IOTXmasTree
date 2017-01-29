using System;
using System.Net.Http;
using Xamarin.Forms;

namespace IOTLightedTreeApp
{
    public partial class MainPage : ContentPage
    {
        public MainPage()
        {
            InitializeComponent();
        }

        // StartClicked
        async void StartClicked(object sender, EventArgs e)
        {
            // call the API
            HttpResponseMessage response = await Client.PostAsync(BaseAddress + "Pin3/", new StringContent(string.Empty));
            await DisplayAlert("Result", 
                                $"Response HttpStatusCode {response.StatusCode}", 
                                "OK");
        }

        // OnOffToggled
        async void OnOffToggled(object sender, ToggledEventArgs e)
        {
            var param = e.Value ? "on/" : "off/";
            // call the API
            HttpResponseMessage response = await Client.PutAsync(BaseAddress + "Pin3/" + param, new StringContent(string.Empty));
            await DisplayAlert("Result",
                                $"Response HttpStatusCode {response.StatusCode}",
                                "OK");
        }

        private string BaseAddress
        {
            get
            {
                return "http://" + txtIPAddr.Text.Trim() + "/";
            }
        }

        #region protected
        // HttpClient to make the calls
        protected HttpClient Client { get; private set; } = new HttpClient();
        #endregion
    }
}
